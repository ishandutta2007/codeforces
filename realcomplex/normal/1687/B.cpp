#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string query;

int ask(vector<int> lis){
    for(auto x : lis) query[x] = '1';
    cout << "? " << query << "\n" ;
    int res;
    cin >> res;
    for(auto x : lis) query[x] = '0';
    return res;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<pii> edg;
    for(int i = 0 ; i < m ; i ++ ){
        query.push_back('0');
 
    }
    vector<pii> weights;
    for(int i = 0 ; i < m ; i ++ ){
        int weight = ask({i});
        weights.push_back(mp(weight, i));
    }    
    sort(weights.begin(), weights.end());
    int las = 0;
    vector<int> need;
    int qq;
    for(int i = 0 ; i < m ; i ++ ){
        need.push_back(weights[i].se);
        qq = ask(need);
        if(qq != las + weights[i].fi){
            need.pop_back();
        }
        else{
            las = qq;
        }
    }
    cout << "! " << las << "\n"; 
    return 0;
}