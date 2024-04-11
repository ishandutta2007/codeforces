
#include <bits/stdc++.h>
 
using namespace std;
 
const int OO = (int) 1e9;
const double eps = 1e-10;

#define trav(a,x) 		for(auto&a:x)
#define lp(i,n) 		for(int i=0;i<int(n);++i)
#define lpi(i,j,n) 		for(int i=j;i<int(n);++i)
#define lpd(i,j,n) 		for(int i=j;i>=int(n);--i)
#define ndl 			cout<<'\n'
#define all(v) 			v.begin(),v.end()
#define rall(v) 		v.rbegin(),v.rend()
#define present(a,x) 	(a.find(x)!=a.end())
#define cpresent(a,x) 	(find(all(a),x)!=a.end())
#define sz(v) 			int(v.size())
#define clr(v, d) 		memset(v,d,sizeof(v))
#define pb 				push_back
#define mp 				make_pair
#define fs 				first
#define sc 				second
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vector<int> > vvi;
typedef map<int, int> mii;
typedef set<int> si;
 
 
class UnionFind {
private:
	vi p, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i) {
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			numSets--;
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				p[y] = x;
				setSize[x] += setSize[y];
			} else {
				p[x] = y;
				setSize[y] += setSize[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int numDisjointSets() {
		return numSets;
	}
	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}
};
 
int n,m,q,op,num;
vi hate;
string s,t;
map<string,int>M;
 
int main() {
	ios::sync_with_stdio(false);
	cout.precision(10);
	cin>>n>>m>>q;
	hate.assign(n,-1);
	UnionFind UF(n);
	lp(i,n){
		cin>>s;
		M[s]=num++;
	}
	lp(i,m){
		cin>>op>>s>>t;
		int s1=UF.findSet(M[s]),s2=UF.findSet(M[t]),s1Opp=hate[s1],s2Opp=hate[s2];
		if (op==1){
			if (s1Opp==s2)
				{cout<<"NO\n";	continue;}
			cout<<"YES\n";
			UF.unionSet(s1,s2);
			if (s1Opp==-1)
				s1Opp=s2Opp;
			if (s2Opp==-1)
				s2Opp=s1Opp;
			if (s1Opp==-1)
				continue;
			UF.unionSet(s1Opp,s2Opp);
			int newS=UF.findSet(s1),newSOpp=UF.findSet(s1Opp);
			hate[newS]=newSOpp,hate[newSOpp]=newS;
		}else{
			if (s1==s2)
				{cout<<"NO\n";	continue;}
			cout<<"YES\n";
			if (s1Opp!=-1)
				UF.unionSet(s1Opp,s2);
			if (s2Opp!=-1)
				UF.unionSet(s2Opp,s1);
			int newS1=UF.findSet(s1),newS2=UF.findSet(s2);
			hate[newS1]=newS2,hate[newS2]=newS1;
		}
		s1=UF.findSet(M[s]),s2=UF.findSet(M[t]),s1Opp=hate[s1],s2Opp=hate[s2];
	}
	lp(i,q){
		cin>>s>>t;
		int s1=UF.findSet(M[s]),s2=UF.findSet(M[t]),s2Opp=hate[s2];
		if (s1==s2)
			cout<<"1\n";
		else if (s1==s2Opp)
			cout<<"2\n";
		else
			cout<<"3\n";
	}
}