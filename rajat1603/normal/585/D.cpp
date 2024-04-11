#include "bits/stdc++.h"
using namespace std;
const int N = 26;
const int inf = 1e9 + 7;
int n;
int l[N];
int m[N];
int w[N];
int mid;
map < pair < int , int > , pair < int , string > > m1;
pair < int , string > ans;
void solve1(int pos , int sum1 , int sum2 , int sum3 , string res){
    if(pos >= mid){
        m1[make_pair(sum2 - sum1 , sum3 - sum2)] = max(m1[make_pair(sum2 - sum1 , sum3 - sum2)] , make_pair(sum1 + inf , res));
    }
    else{
        solve1(pos + 1 , sum1 + l[pos] , sum2 + m[pos] , sum3 , res + "LM\n");
        solve1(pos + 1 , sum1 + l[pos] , sum2 , sum3 + w[pos] , res + "LW\n");
        solve1(pos + 1 , sum1 , sum2 + m[pos] , sum3 + w[pos] , res + "MW\n");
    }
}
void solve2(int pos , int sum1 , int sum2 , int sum3 , string res){
    if(pos < mid){
        if(m1.find(make_pair(sum1 - sum2 , sum2 - sum3)) != m1.end()){
            reverse(res.begin() , res.end());
            auto it = m1[make_pair(sum1 - sum2 , sum2 - sum3)];
            ans = max(ans , make_pair(it.first - inf + sum1 , it.second + res));
        }
    }
    else{
        solve2(pos - 1 , sum1 + l[pos] , sum2 + m[pos] , sum3 , res + "\nML");
        solve2(pos - 1 , sum1 + l[pos] , sum2 , sum3 + w[pos] , res + "\nWL");
        solve2(pos - 1 , sum1 , sum2 + m[pos] , sum3 + w[pos] , res + "\nWM");
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> l[i] >> m[i] >> w[i];
    }
    mid = (n >> 1) + 1;
    ans.first = -inf;
    ans.second = "Impossible";
    solve1(1 , 0 , 0 , 0 , "");
    solve2(n , 0 , 0 , 0 , "");
    cout << ans.second;
}