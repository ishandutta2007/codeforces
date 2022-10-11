// Not my code https://codeforces.com/blog/entry/102489
 
#include<bits/stdc++.h>
using namespace std;
 
#define MM 6000
#define MOD 1000000007
#define MAXX 9999999
#define PI 3.14159265358979323846
#define ep emplace_back
#define pb push_back
#define mk make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define watch1(a) cerr <<#a<<": "<<a<<"\n";
#define watch2(a,b) cerr <<#a<<": "<<a<<", "<<#b<<": "<<b<< "\n";
#define watch3(a,b,c) cerr <<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<"\n";
#define watch4(a,b,c,d) cerr<<#a<<": "<<a<<", "<<#b<<": "<<b<<", "<<#c<<": "<<c<<", "<<#d<<": "<<d<<"\n";
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> PII;
typedef pair<lli,lli> PLL;
typedef tuple<int,int,int> tp;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
//    freopen("input.txt", "r", stdin);
 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
 
        unordered_map<double, int> mp;
        mp.reserve(3*n+10);
        double sum = 0.0;;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum += v[i];
            mp[v[i]]++;
        }
 
        double avg = sum/n;
        double reqSum = avg * 2;
 
        lli ans = 0;
        for(auto it = mp.begin();it!=mp.end();it++){
            double x = it->first;
            double y = reqSum - x;
            if(x==y){
                lli cnt = mp[x];
                ans += (cnt*(cnt-1));
            } else {
                lli cntA = mp[x];
                lli cntB = mp[y];
                ans += (cntA * cntB);
            }
        }
 
        cout << ans/2 << "\n";
    }
}