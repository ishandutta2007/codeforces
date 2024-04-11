#include <bits/stdc++.h>
//#define int long long
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,long long>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
using namespace std;
vi a;
long long oneSeq(int n){
    vi places (n,-1);
    for (int i=0;i<2*n;i++){
        if (a[i]>=0){
            if (places[a[i]]==-1) {
                places[a[i]]=i;
                a[i]=-1;
            }
        }
    }

    long long sum=places[0];
    for(int i=1;i<n;i++){
        if (places[i]-places[i-1]>0) sum+=places[i]-places[i-1];
        else sum+=-places[i]+places[i-1];
    }
    return sum;
}
int main()
{
    cout << fixed << showpoint << setprecision(15);
    int n,x;
    cin >> n;
    a.resize(2*n);
    for(int i=0;i<2*n;i++){
       cin >>x; a[i]=--x;
    }
    cout << oneSeq(n)+oneSeq(n) <<endl;
    return 0;
}