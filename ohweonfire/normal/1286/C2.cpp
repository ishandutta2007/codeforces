// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

vector<string> query(int l,int r)
{
	if(l>r)return vector<string>();
	cout<<"? "<<l<<" "<<r<<endl;
	vector<string>ret;
	for(int i=l;i<=r;i++)for(int j=i;j<=r;j++)
	{
		string s;cin>>s;
		sort(s.begin(),s.end());
		ret.pb(s);
	}
	return ret;
}

int n,cnt1[111][26],chk1[111][26],cnt2[111][26],chk2[111][26],cnt3[111][26],chk3[111][26];

void construct(int cntv[111][26],int chk[111][26],vector<string> v1,int n)
{
	for(int j=0;j<(int)v1.size();j++)for(int k=0;k<(int)v1[j].size();k++)cntv[v1[j].size()][v1[j][k]-'a']++;
	
	for(int c=0;c<26;c++)
	{
		int all=cntv[n][c];
		for(int i=1;i<=n/2;i++)
		{
			//all other have (i+1) except i
			int num=all*(i+1)-cntv[n-i][c];
			all-=num;chk[i][c]=num;
			for(int j=i+1;j<=n;j++)cntv[j][c]-=num*i;
		}
		if(all)chk[(n+1)/2][c]=all;
	}
}

int ans[111][26];
int main()
{
	cin>>n;
	vector<string> v3=query(1,n);
	construct(cnt3,chk3,v3,n);
	if(n==1)
	{
		cout<<"! "<<v3[0]<<endl;
		return 0;
	}
	
	int m=n/2;
	vector<string> v1=query(1,m);
	construct(cnt1,chk1,v1,m);
	vector<string> v2=query(1,m-1);
	construct(cnt2,chk2,v2,m-1);
//	for(int i=1;i<=n;i++)for(int j=0;j<26;j++)if(chk1[i][j])printf("%d %d c= %d\n",i,j,chk1[i][j]);
//	puts("");
//	for(int i=1;i<=n;i++)for(int j=0;j<26;j++)if(chk1[i][j])printf("%d %d c= %d\n",i,j,chk2[i][j]);
//	puts("");
	if(m%2==0)
	{
		for(int i=m/2;i>=1;i--)
		{
			memcpy(ans[i],chk2[i],sizeof(ans[i]));
			for(int j=0;j<26;j++)chk1[i][j]-=ans[i][j];
			memcpy(ans[m-i+1],chk1[i],sizeof(ans[i]));
			for(int j=0;j<26;j++)chk2[i-1][j]-=ans[m-i+1][j];
		}
	}
	else
	{
		memcpy(ans[m/2+1],chk1[m/2+1],sizeof(ans[0]));
		for(int j=0;j<26;j++)chk2[m/2][j]-=ans[m/2+1][j];
		for(int i=m/2;i>=1;i--)
		{
			memcpy(ans[i],chk2[i],sizeof(ans[i]));
			for(int j=0;j<26;j++)chk1[i][j]-=ans[i][j];
			memcpy(ans[m-i+1],chk1[i],sizeof(ans[i]));
			for(int j=0;j<26;j++)chk2[i-1][j]-=ans[m-i+1][j];
		}
	}
	
	for(int i=1;i<=m;i++)for(int j=0;j<26;j++)chk3[i][j]-=ans[i][j];
	for(int i=m+1;i<=n;i++)memcpy(ans[i],chk3[n-i+1],sizeof(ans[i]));
	
	printf("! ");
	for(int i=1;i<=n;i++)
	{
		int piv=0,sum=0;
		for(int j=0;j<26;j++)if(ans[i][j])
		{
			piv=j;
			sum+=ans[i][j];
		}
		assert(sum<=1);
		putchar(piv+'a');
	}
	cout<<endl;
	
	return 0;
}