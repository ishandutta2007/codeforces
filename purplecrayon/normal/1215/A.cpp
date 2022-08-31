/* Justin Choi */
#include <bits/stdc++.h>
using namespace std;

string FILENAME = "filename";
#define io ifstream fin(FILENAME + ".in"); ofstream fout(FILENAME + ".out")
#define fwrite(X) fout << X;
#define fwriteln(X) fout << X << endl;
#define qio ios_base::sync_with_stdio(false); cin.tie(NULL)

#define forl(V, N) for(int V = 0; V < N; V++)
#define for1(V, N) for(int V = 1; V <= N; V++)
#define fore(E, X) for(auto &E:X)
#define newl cout << endl
#define println(X) cout << X << endl
#define printe(X) for(auto &E:X) cout << E << " "; cout << endl
#define rem(X) X.top(); X.pop()
#define setmin(A, B) A = min(A, B)
#define setmax(A, B) A = max(A, B)

#define graph unordered_map<int, unordered_set<int>>
#define um unordered_map
#define us unordered_set
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ins insert

int n,a,b,k,l,w;
int main(){
	cin>>a>>b>>k>>l>>n;
	if(k<l)swap(k,l),swap(a,b);
	cout<<max(n-a*(k-1)-b*(l-1),0)<<" ";
	w=min(b,n/l);
	cout<<w+min(a,(n-w*l)/k);
}