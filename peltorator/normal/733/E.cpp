#include <bits/stdc++.h>

using namespace std;

long long ans[1000001];

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int rr = 0,num = 0;
    long long v = 1, v2 = 1;
    for (int i = 0; i < n; i++)
    {
        num++;
        v -= i;
        while(rr < n && num > 0)
        {
            if(s[rr] == 'D')
            {
                v += 2 * rr;
                num--;
            }
            rr++;
        }
        if(num)
            break;
        ans[i] = v;
        v -= i;
    }
    for (int i = 0; i < n; i++)
    {
        if(s[i] == 'U')
            s[i] = 'D';
        else
            s[i] = 'U';
    }
    rr = 0;
    num = 0;
    v = 1;
    v2 = 1;
    for (int i = 0; i < n; i++)
    {
        num++;
        v -= i;
        while(rr < n && num > 0){
            if(s[s.size() - rr - 1] == 'D'){
                v += 2 * rr;
                num--;
            }
            rr++;
        }
        if(num)
            break;
        ans[n - 1 - i] = v;
        v -= i;
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}