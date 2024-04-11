#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1.2e6+5;
const int p=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

inline int min(int x,int y){return x<y?x:y;}
int a[N];
char b[N];
vector<int>dp[N];
vector<pair<int,int>>q[N];
int rk[N],sa[N],tp[N],cnt[N],st[21][N],Log[N],pos[N];
// 
#define L_TYPE 0
#define S_TYPE 1

// LMS
inline bool is_lms_char(int *type, int x)
{
	return x > 0 && type[x] == S_TYPE && type[x - 1] == L_TYPE;
}

// LMS
inline bool equal_substring(int *S, int x, int y, int *type)
{
	do
	{
		if (S[x] != S[y])
			return false;
		x++, y++;
	} while (!is_lms_char(type, x) && !is_lms_char(type, y));

	return S[x] == S[y];
}

// (*LLS)
// *SA
inline void induced_sort(int *S, int *SA, int *type, int *bucket, int *lbucket,
						 int *sbucket, int n, int SIGMA)
{
	for (int i = 0; i <= n; i++)
		if (SA[i] > 0 && type[SA[i] - 1] == L_TYPE)
			SA[lbucket[S[SA[i] - 1]]++] = SA[i] - 1;
	for (int i = 1; i <= SIGMA; i++) // Reset S-type bucket
		sbucket[i] = bucket[i] - 1;
	for (int i = n; i >= 0; i--)
		if (SA[i] > 0 && type[SA[i] - 1] == S_TYPE)
			SA[sbucket[S[SA[i] - 1]]--] = SA[i] - 1;
}

// SA-IS
// Slength, SIGMA
static int *SAIS(int *S, int length, int SIGMA)
{
	int n = length - 1;
	int *type = new int[n + 1];		   // 
	int *position = new int[n + 1];	   // LMS
	int *name = new int[n + 1];		   // LMS
	int *SA = new int[n + 1];		   // SA
	int *bucket = new int[SIGMA + 1];  // 
	int *lbucket = new int[SIGMA + 1]; // L
	int *sbucket = new int[SIGMA + 1]; // S

	// 
	memset(bucket, 0, sizeof(int) * (SIGMA + 1));
	for (int i = 0; i <= n; i++)
		bucket[S[i]]++;
	lbucket[0] = sbucket[0] = 0;
	for (int i = 1; i <= SIGMA; i++)
	{
		bucket[i] += bucket[i - 1];
		lbucket[i] = bucket[i - 1];
		sbucket[i] = bucket[i] - 1;
	}

	// (2.1)
	type[n] = S_TYPE;
	for (int i = n - 1; i >= 0; i--)
	{
		if (S[i] < S[i + 1])
			type[i] = S_TYPE;
		else if (S[i] > S[i + 1])
			type[i] = L_TYPE;
		else
			type[i] = type[i + 1];
	}

	// LMS
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (type[i] == S_TYPE && type[i - 1] == L_TYPE)
			position[cnt++] = i;

	// LMS
	fill(SA, SA + n + 1, -1);
	for (int i = 0; i < cnt; i++)
		SA[sbucket[S[position[i]]]--] = position[i];
	induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);

	// LMS
	fill(name, name + n + 1, -1);
	int lastx = -1, namecnt = 1; // LMS
	bool flag = false;			 // 
	for (int i = 1; i <= n; i++)
	{
		int x = SA[i];

		if (is_lms_char(type, x))
		{
			if (lastx >= 0 && !equal_substring(S, x, lastx, type))
				namecnt++;
			// LMS
			if (lastx >= 0 && namecnt == name[lastx])
				flag = true;

			name[x] = namecnt;
			lastx = x;
		}
	} // for
	name[n] = 0;

	// S1
	int *S1 = new int[cnt];
	int pos = 0;
	for (int i = 0; i <= n; i++)
		if (name[i] >= 0)
			S1[pos++] = name[i];

	int *SA1;
	if (!flag)
	{
		// SA1
		SA1 = new int[cnt + 1];

		for (int i = 0; i < cnt; i++)
			SA1[S1[i]] = i;
	}
	else
		SA1 = SAIS(S1, cnt, namecnt); // SA1

	// SA1SA
	lbucket[0] = sbucket[0] = 0;
	for (int i = 1; i <= SIGMA; i++)
	{
		lbucket[i] = bucket[i - 1];
		sbucket[i] = bucket[i] - 1;
	}
	fill(SA, SA + n + 1, -1);
	for (int i = cnt - 1; i >= 0; i--) // SA1SAS
		SA[sbucket[S[position[SA1[i]]]]--] = position[SA1[i]];
	induced_sort(S, SA, type, bucket, lbucket, sbucket, n, SIGMA);

	// 
	return SA;
}
void get_height(int n,int *a)
{
	for (int i=1,k=0;i<=n;i++)
	{
		if (k) k--;
		if (rk[i]>1) while (a[i+k]==a[sa[rk[i]-1]+k]) k++;
		st[0][rk[i]-1]=k;
	}
	for (int i=2;i<=n;i++) Log[i]=Log[i/2]+1;
	for (int j=1;j<21;j++)
	for (int i=1;i+(1<<j)-1<=n;i++)
	st[j][i]=min(st[j-1][i],st[j-1][i+(1<<(j-1))]);
}
inline int query(int x,int y)
{
	if (x==y) return N;
	x=rk[x],y=rk[y];
	if (x>y) swap(x,y);
	int k=Log[y-x];
	return min(st[k][x],st[k][y-(1<<k)]);
}
int cmp(int x1,int y1,int x2,int y2)
{
	int z1=pos[x1],z2=pos[x2],l=min(y1,y2),r=max(y1,y2);
	int tmp=query(z1,z2);
	if (tmp<l) return a[z1+tmp]<a[z2+tmp]?-1:1;
	if (y1<y2)
	{
		tmp=query(z1+l+1,z2+l);
		if (tmp<r-l) return a[z1+l+1+tmp]<a[z2+l+tmp]?-1:1;
	}
	else
	{
		tmp=query(z1+l,z2+l+1);
		if (tmp<r-l) return a[z1+l+tmp]<a[z2+l+1+tmp]?-1:1;
	}
	tmp=query(z1+r+1,z2+r+1);
	if (r+1+tmp>=(int)max(dp[x1].size(),dp[x2].size())) return 0;
	return a[z1+r+1+tmp]<a[z2+r+1+tmp]?-1:1;
}

signed main()
{
//	freopen("input","r",stdin);
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++)
	{
		scanf("%s",b);
		int len=strlen(b)+1;
		b[len-1]='#',dp[i].resize(len),pos[i]=cnt+1;
		for (int j=0;j<len;j++) a[++cnt]=b[j];
		a[++cnt]='#';
	}
	int *SA=SAIS(a+1,cnt+2,128);
	for (int i=1;i<=cnt;i++) rk[sa[i]=SA[i+1]+1]=i;
	get_height(cnt,a);
	auto less=[&](pair<int,int>a,pair<int,int>b){
		int tmp=cmp(a.first,a.second,b.first,b.second);
		if (tmp) return tmp<0;
		return a<b;
	};
	for (int i=1;i<=n;i++)
	{
		q[i].resize(dp[i].size());
		for (int j=0;j<(int)dp[i].size();j++) q[i][j]={i,j};
		stable_sort(q[i].begin(),q[i].end(),less);
	}
	for (int &i:dp[1]) i=1;
	for (int i=2;i<=n;i++)
	{
		int sum=0,j=0,k=0;
		while (j<(int)dp[i-1].size()&&k<(int)dp[i].size())
		if (less(q[i-1][j],q[i][k])) (sum+=dp[i-1][q[i-1][j++].second])>=p?sum-=p:0;
								else dp[i][q[i][k++].second]=sum;
		while (k<(int)dp[i].size()) dp[i][q[i][k++].second]=sum;
	}
	int sum=0;
	for (int i:dp[n]) sum=(sum+i)%p;
	print(sum);
	
	return 0;
}