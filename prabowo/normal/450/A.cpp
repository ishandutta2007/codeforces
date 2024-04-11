#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    int i,j,k;
    queue <pair<long, long> > q;
    cin >> n >> m;
    int a;
    for(i=1; i<=n; i++){cin >> a; q.push(make_pair(a,i));}
    while(q.size() > 1){
        if (q.front().first > m) q.push(make_pair(q.front().first-m,q.front().second));
        q.pop();
    }
    cout << q.front().second << endl;
    return 0;
}