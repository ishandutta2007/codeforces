#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

const int MAXN=100111;
const int MAXK=20;
const int MAXZ=27;
const ull BASE=29ULL;

string input;
int N, K, L[MAXK];
int Num[MAXN];
ull Hash[MAXN], Pow[MAXN];
bool F[MAXN][MAXK];
int Pre[MAXN][MAXZ], Nxt[MAXN][MAXZ], App[MAXZ];
long long Cost[MAXN];
long long Val[MAXN][MAXZ];
long long Sum;

ull H(int l, int r){
	return Hash[r]-Hash[l-1]*Pow[r-l+1];
}

int lcp(int a, int b){
	int len=min(N-a+1, N-b+1);
	int l=0, r=len, m;
	while(l<r){
		m=(l+r)>>1;
		if(H(a, a+m)==H(b, b+m))	l=m+1;
		else	r=m;
	}
	m=(l+r)>>1;
	return m;
}

int Diff1(int l1, int r1, int l2, int r2){
	int r;
	int l=lcp(l1, l2);
	l1+=l;l2+=l;
	if(l1>r1 || l2>r2)	return -1;
	r=l1;
	++l1;++l2;
	l=lcp(l1, l2);
	l1+=l;l2+=l;
	if(l1>r1 && l2>r2)	return r;
	return -1;
}

void Add(int l, int r, long long v){
	Cost[l]+=v;Cost[r+1]-=v;
	Sum+=v;
}

int main(){
	
	cin >> input;
	N=input.length();
	for(int i=1;i<=N;++i)	Num[i]=input[i-1]-'a'+1;
	
	K=1;L[1]=1;
	while(L[K]<<1<N)	{++K;L[K]=(L[K-1]<<1)+1;}
	
	for(int i=1;i<=26;++i)	App[i]=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=26;++j)
			Pre[i][j]=App[j];
		App[Num[i]]=i;
	}
	
	for(int i=1;i<=26;++i)	App[i]=N+1;
	for(int i=N;i>=1;--i){
		for(int j=1;j<=26;++j)
			Nxt[i][j]=App[j];
		App[Num[i]]=i;
	}
	
	Hash[0]=0ULL;
	for(int i=1;i<=N;++i)	Hash[i]=Hash[i-1]*BASE+(ull)(Num[i]);
	
	Pow[0]=1ULL;
	for(int i=1;i<=N;++i)	Pow[i]=Pow[i-1]*BASE;
	
	for(int i=1;i<=N;++i){
		Add(i, i, 1LL);
		for(int j=1;j<=26;++j)	Val[i][j]+=1LL;
		F[i][1]=true;
	}
	
	for(int k=2;k<=K;++k){
		for(int i=1, j=i+L[k]-1, m, a, b, dl, dr;j<=N;++i, ++j){
			m=(i+j)>>1;a=(i+m-1)>>1;b=(m+1+j)>>1;
			F[m][k]=F[a][k-1] && F[b][k-1] && F[m][k-1];
			F[m][k]=F[m][k] && Num[a]==Num[b];
			F[m][k]=F[m][k] && Pre[m][Num[m]]<i && Nxt[m][Num[m]]>j;
			if(F[m][k]){
				//cout << m << " " << k << endl;
				Add(i, j, 1LL*L[k]*L[k]);
			}
			for(int c=1;c<=26;++c){
				if(F[a][k-1] && F[b][k-1] && H(i, m-1)==H(m+1, j) && Pre[m][c]<i && Nxt[m][c]>j)
					Val[m][c]+=1LL*L[k]*L[k];
			}
			dl=Diff1(i, m-1, m+1, j);
			if(dl>0 && F[b][k-1] && Nxt[m][Num[m]]>j)	Val[dl][Num[dl-i+m+1]]+=1LL*L[k]*L[k];
			dr=Diff1(m+1, j, i, m-1);
			if(dr>0 && F[a][k-1] && Pre[m][Num[m]]<i)	Val[dr][Num[dr-m-1+i]]+=1LL*L[k]*L[k];
		}
	}
	
	for(int i=1;i<=N;++i)	Cost[i]+=Cost[i-1];
	/*aaabaca
	cout << Diff1(1, 3, 5, 7) << endl;
	cout << lcp(1, 5) << endl;
	cout << H(1, 1) << " " << H(5, 5) << endl;
	
	cout << Sum << endl;
	
	for(int i=1;i<=N;++i)
		cout << Val[i][3] << " ";
	cout << endl;
	
	for(int i=1;i<=N;++i)
		cout << Cost[i] << " ";
	cout << endl;
	*/
	
	//cout << Sum << endl;
	
	long long Del=0LL;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=26;++j)
			Del=max(Del, Val[i][j]-Cost[i]);
	}
	
	cout << Sum+Del << endl;
	
	return 0;
}