#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

priority_queue<int> unused[3];
priority_queue<int, vector<int>, greater<int>> used[3];

const int M = (int)3e5 + 91;

ll mx[M];

void calc(){
    ll sum = 0;
    int tw = 0;
    if(unused[1].empty()){
        while(!unused[2].empty()){
            sum += unused[2].top();
            unused[2].pop();
            tw += 2;
            mx[tw] = sum;
        }
    }
    else{
        int t = unused[1].size() + 2 * unused[2].size();
        int x, y, z;
        for(int i = 1; i <= t; i ++ ){
            if(!unused[1].empty()){
                sum += unused[1].top();
                used[1].push(unused[1].top());
                unused[1].pop();
            }
            else{
                unused[1].push(used[1].top());
                sum -= used[1].top();
                used[1].pop();

                used[2].push(unused[2].top());
                sum += unused[2].top();
                unused[2].pop();
            }
            while(used[1].size() >= 2 && unused[2].size() >= 1){
                x = used[1].top(); used[1].pop();
                y = used[1].top(); used[1].pop();
                if(x + y < unused[2].top()){
                    sum -= x + y;
                    sum += unused[2].top();
                    used[2].push(unused[2].top());
                    unused[2].pop();
                    unused[1].push(x);
                    unused[1].push(y);
                }
                else{
                    used[1].push(x);
                    used[1].push(y);
                    break;
                }
            }
            mx[i] = sum;
        }
    }
    for(int i = 1; i < M; i ++ )
        mx[i] = max(mx[i], mx[i-1]);
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int w, c;
    vector<int> ss;
    for(int i = 0 ; i < n; i ++ ){
        cin >> w >> c;
        if(w < 3){
            unused[w].push(c);
        }
        else{
            ss.push_back(c);
        }
    }
    calc();
    ll answ = mx[m];
    sort(ss.begin(), ss.end());
    reverse(ss.begin(), ss.end());
    ll ssum = 0;
    for(int i = 0 ; i < ss.size() ; i ++ ){
        ssum += ss[i];
        m -= 3;
        if(m>=0)
            answ = max(answ, ssum + mx[m]);
    }
    cout << answ;
    return 0;
}