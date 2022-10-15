#include <bits/stdc++.h>
using namespace std;
 #define MOD 1000000007
 #define A '@'
 #define B '*'
 #define C '#'
 #define max(a,b) ((a>b)?a:b)
 #define min(a,b) ((a<b)?a:b)
 #define endl "\n"
 struct frac {long x; long y;};
 frac operator+(frac a, frac b)
 {
 	frac res;
 	res.x=((a.x)*(b.y))%MOD+((b.x)*(a.y))%MOD;
 	res.x%=MOD;
 	res.y=a.y*b.y;
 	res.y%=MOD;
 	return res;
 }
 
 long long bow (long long a, long long x)
 {
 	if (!x) return 1;
	long long res=bow(a,x/2);
	res*=res; res%=MOD;
	if (x%2) res*=a;
	return (res)%MOD;
 }
 
 long long get_mod(long long x, long long y)
 {
 	long long d=__gcd(x,y);
 	x/=d;
 	y/=d;
 	x%=MOD;
 	y%=MOD;
 	return (x*(bow(y,MOD-2)))%MOD;
 }
 
 
 
typedef vector<int> vi;
 
// Union-Find Disjoint Sets Library
// PS: This library code does not include the `union by rank' heuristic yet
// 1000 is just a rough number, adjustable by user
vi pset(3000), setSize(3000); 
 
int _numDisjointSets;
 
void initSet(int N) { 
     setSize.assign(N, 1); 
     _numDisjointSets = N; 
     pset.assign(N, 0); 
     for (int i = 0; i < N; i++) pset[i] = i; 
}
 
int findSet(int i) { 
    return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); 
}
 
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
 
void unionSet(int i, int j) { 
  if (!isSameSet(i, j)) { 
    _numDisjointSets--; 
    setSize[findSet(j)] += setSize[findSet(i)]; 
    pset[findSet(i)] = findSet(j); } 
}
 
int numDisjointSets() { return _numDisjointSets; }
 
int sizeOfSet(int i) { return setSize[findSet(i)]; }
 
 
 
 
long long t,k,n,m, i,j,jj,mid,a,b,c,d,root;
vector <frac> snake1,snake2,snake;
long long dp[100001],pre[100001];
vector <long long> child[2501];
vector<long long> ord[2501];
char res[101][101],cc;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   cin>>a>>b>>c>>d>>n;
   for (i=1;i<=100;i++) for (j=1;j<=100;j++) res[i][j]='.';
   for (j=1;j<=a;j++) 
   {
   	if (j%2) for (i=1;i<=b;i++)
   	snake1.push_back({i,a+1-j});
   	else for (i=b;i>=1;i--)
   	snake1.push_back({i,a+1-j});
   	
   }
   for (j=1;j<=c;j++) 
   {
   	if (j%2) for (i=1;i<=d;i++)
   	snake2.push_back({i,j+a});
   	else for (i=d;i>=1;i--)
   	snake2.push_back({i,j+a});
   	
   }
   for (i=c*d-1;i>=0;i--) snake.push_back(snake2[i]);
   for (i=0;i<a*b;i++) snake.push_back(snake1[i]);
   j=-1;
   for (i=0;i<n;i++)
   {
   	cin>>t;
   	cc=97+i;
   	for (k=0;k<t;k++)
   	{
   		j++;
	   	res[snake[j].x][snake[j].y]=cc;
   	}
   }
   cout<<"YES"<<endl;
   for (i=1;i<=max(b,d);i++)
   {
   	
   for (j=1;j<=a+c;j++) cout<<res[i][j]; cout<<endl;
   }
}
/*
1880/1900
*/