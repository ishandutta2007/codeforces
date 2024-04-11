#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[1010];

int main(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%d", a+i);
    stack<int> st1, st2;
    ll ans = 0;
    for (int i=0;i<n;i++){
        if (!(i&1)) {st1.push(a[i]); continue;}
        int cur = a[i];
        while(!st1.empty() && st1.top()<cur){
            ans += st1.top();
            cur -= st1.top(); st1.pop();
            if (!st2.empty()){
                ans += st2.top(); st2.pop();
            }
        }

        if (st1.empty()) continue;
        if (st1.top()>cur){
            ans += cur;
            int tmp = st1.top(); st1.pop();
            st1.push(tmp-cur);
            st2.push(1);
        }
        else{
            ans += cur;
            st1.pop();
            int tmp = 0;
            if (!st2.empty()) {ans += st2.top(); tmp = st2.top(); st2.pop();}
            st2.push(tmp+1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}