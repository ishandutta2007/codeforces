#include <bits/stdc++.h>
//#define int long long
#define vi vector<int>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ii pair<int,int>
#define x first
#define y second
#define abs(x) ((x>0)?(x):(-x))
#define all(x) x.begin(), x.end()
#define INFI 9e18
using namespace std;

long long a(long long a,long long b, long long c){
    long long cur=-b/(2*a);
    while (a*cur*cur+b*cur+c<0){
        cur++;
    }
    return cur;

}

int main(){
    long long n,m,mi;
    cin>>n>>m;
    mi=n-m*2;
    cout << (mi>0?mi:0) <<" " <<(n- a(1,-1,-2*m) )<<endl;
}