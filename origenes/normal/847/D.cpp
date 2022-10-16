#include <iostream>
#include <queue>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > q;
int n, T, t, lb, ub, cur, res;
int main(){
    cin>>n>>T;
    for(int i=1; i<=n; i++){
        cin>>t;
        lb=max(t-i, 0);
        ub=T-i;
        if(ub>lb){
            q.push(make_pair(lb, 1));
            q.push(make_pair(ub, -1));
        }
    }
    while(!q.empty()){
        cur+=q.top().second;
        q.pop();
        res=max(res, cur);
    }
    cout<<res<<endl;
    return 0;
}