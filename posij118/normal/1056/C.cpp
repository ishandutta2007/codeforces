#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, t, cnt;
    cnt = 0;
    pair<int, int> pr;
    cin >> n >> m;

    int paired[2*n];

    int inp[2*n];
    for(int i = 0; i<2*n; i++){
        cin >> inp[i];
    }

    for(int i = 0; i<2*n; i++){
        paired[i] = -1;
    }

    priority_queue<pair<int, int> > P;
    for(int i = 0; i<2*n; i++){
       P.push(make_pair(inp[i], i + 1));
    }

    int a[m], b[m];
    for(int i = 0; i<m; i++){
        cin >> a[i] >> b[i];
        paired[a[i] - 1] = b[i] - 1;
        paired[b[i] - 1] = a[i] - 1;
    }

    int ptr = 0;
    bool used[m];
    bool av[2*n];
    fill(used, used + m, 0);
    fill(av, av + 2*n, 0);
    cin >> t;

    if(t == 1){
        while(ptr < m){
            if(used[ptr] == 0){
                if(inp[a[ptr] - 1] > inp[b[ptr] - 1]){
                    cout << a[ptr] << endl;
                    fflush(stdout);
                }

                else{
                   cout << b[ptr] << endl;
                    fflush(stdout);
                }

                cin >> x;
                used[ptr] = 1;
                av[a[ptr] - 1] = 1;
                av[b[ptr] - 1] = 1;
            }

            ptr++;
        }

        while(!P.empty()){
            pr = P.top();
            P.pop();
            if(av[pr.second - 1] == 0){
                cout << pr.second << endl;
                fflush(stdout);
                cin >> x;
                av[x - 1] = 1;

            }
        }

    }

    else{
        while(1){
            cin >> x;
            cnt++;
            av[x - 1] = 1;
            if(paired[x - 1] == -1) break;
            
            cout << paired[x - 1] + 1 << endl;
           
            fflush(stdout);
            cnt++;
            if(cnt == 2*n) break;

            av[paired[x - 1]] = 1;

        }

        while(ptr < m){
            if(av[a[ptr] - 1] == 0){
                if(inp[a[ptr] - 1] > inp[b[ptr] - 1]){
                    cout << a[ptr] << endl;
                    fflush(stdout);
                    cnt++;
                }

                else{
                   cout << b[ptr] << endl;
                    fflush(stdout);
                    cnt++;
                }

                cin >> x;
                cnt++;
                used[ptr] = 1;
                av[a[ptr] - 1] = 1;
                av[b[ptr] - 1] = 1;
            }

            ptr++;
        }

        while(!P.empty()){
            pr = P.top();
            P.pop();
            if(av[pr.second - 1] == 0){
                cout << pr.second << endl;
                fflush(stdout);
                cnt++;
                if(cnt == 2*n) break;
                cin >> x;
                cnt++;
                av[x - 1] = 1;

            }
        }
    }
}