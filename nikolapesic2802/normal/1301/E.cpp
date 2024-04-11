
// Problem : E. Nanosoft
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/E
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define D(x) cerr << #x << " is " << (x) << "\n";
#define ld long double

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const deque<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T,greater<T> >& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=502;
int sum[N][N][4],n,m,q;
int mapa[N][N];
int cnt[N][N][N/2];
bool ok(int x1,int y1,int x2,int y2,int i){
	if(x1>x2||y1>y2)
		return 1;
	if(x1<0||y1<0||x2>=n||y2>=m)
		return 0;
	int ans=sum[x2][y2][i];
	if(x1)
		ans-=sum[x1-1][y2][i];
	if(y1)
		ans-=sum[x2][y1-1][i];
	if(x1&&y1)
		ans+=sum[x1-1][y1-1][i];
	return ans==(x2-x1+1)*(y2-y1+1);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%i %i %i",&n,&m,&q);
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<m;j++){
			if(s[j]=='R')
				mapa[i][j]=0;
			if(s[j]=='G')
				mapa[i][j]=1;
			if(s[j]=='Y')
				mapa[i][j]=2;
			if(s[j]=='B')
				mapa[i][j]=3;
			sum[i][j][mapa[i][j]]++;
			for(int k=0;k<4;k++){
				if(i)
					sum[i][j][k]+=sum[i-1][j][k];
				if(j)
					sum[i][j][k]+=sum[i][j-1][k];
				if(i&&j)
					sum[i][j][k]-=sum[i-1][j-1][k];
			}
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<m-1;j++){
			int l=0,r=N-1;
			while(l<r){
				int m=(l+r+1)>>1;
				if(ok(i-m+1,j-m+1,i,j,0)&&ok(i-m+1,j+1,i,j+m,1)&&ok(i+1,j-m+1,i+m,j,2)&&ok(i+1,j+1,i+m,j+m,3))
					l=m;
				else
					r=m-1;
			}
			for(int k=1;k<=l;k++){
				cnt[i-k+1][j-k+1][k]++;
				//printf("%i %i: %i\n",i-k+1,j-k+1,k);
			}
		}
	}
	/*for(int i=1;i<N;i++){
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				cnt[i][j][k]+=cnt[i-1][j][k];
	}*/
	for(int i=0;i<N;i++){
		for(int j=1;j<N;j++)
			for(int k=0;k<N/2;k++)
				cnt[i][j][k]+=cnt[i][j-1][k];
	}
	for(int i=0;i<q;i++){
		int x1,y1,x2,y2;
		scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
		x1--;y1--;x2--;y2--;
		int ans=0;
		for(int i=x1;i<=x2;i++){
			int prostora=(ans+1)*2;
			if(i>x2-prostora+1)
				break;
			int rght=y2-prostora+1;
			if(y1<=rght){
				int c=cnt[i][rght][ans+1];
				if(y1)
					c-=cnt[i][y1-1][ans+1];
				if(c)
					ans++,i=max(x1-1,i-2);
			}
		}
		/*
		int l=0,r=N/2;
		while(l<r){
			int mid=(l+r+1)>>1;
			int prostora=mid*2;
			bool javlja=0;
			for(int i=x1;!javlja&&i<=x2-prostora+1;i++){
				int rght=y2-prostora+1;
				if(y1<=rght){
					int c=cnt[i][rght][mid];
					if(y1)
						c-=cnt[i][y1-1][mid];
					if(c)
						javlja=1;
				}
			}
			if(javlja)
				l=mid;
			else
				r=mid-1;
		}
		*/
		printf("%i\n",4*ans*ans);
	}
	return 0;
}