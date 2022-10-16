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
#define ff fflush(stdout);
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string pitaj;
void solve(int a,int b){
    int n=a+b;
    if(a==0){
        for(int i=0;i<n;i++){
            pitaj[i]='b';
        }
        cout << pitaj << endl;
        exit(0);
    }
    if(b==0){
        for(int i=0;i<n;i++){
            pitaj[i]='a';
        }
        cout << pitaj << endl;
        exit(0);
    }
    for(int i=0;i<n;i++)
        pitaj[i]='a';
    pitaj[n-1]='b';
    int zaB=b-1;
    cout << pitaj << endl;
    ff;
    int aa;
    scanf("%i",&aa);
    if(aa==0)
        exit(0);
    if(aa==zaB)
        solve(a,b-1);
    else
        pitaj[n-1]='a',solve(a-1,b);
}
int main()
{
    int a,b;
    string prvi(300,'a'),drugi(300,'b');
    cout << prvi << endl;
	ff;
	scanf("%i",&a);
	if(a==0)
        return 0;
	a=300-a;
	cout << drugi << endl;
	ff;
	scanf("%i",&b);
	if(b==0)
        return 0;
	b=300-b;
	for(int i=0;i<a+b;i++)
        pitaj+='c';
    solve(a,b);
    return 0;
}