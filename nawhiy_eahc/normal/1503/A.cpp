#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int one = 0;
        for(int i=0;i<n;i++) if(s[i] == '1') one++;

        if(one%2)
        {
            cout << "NO\n";
            continue;
        }

        int now = 1, curr1 = 0, curr2 = 0; bool how = true, ans = true;

        string t1 = s, t2 = s;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
            {
                if(now <= one/2)
                {
                    t1[i] = '(';
                    t2[i] = '(';
                    curr1++; curr2++;
                }
                else
                {
                    t1[i] = ')';
                    t2[i] = ')';
                    curr1--; curr2--;
                }

                now++;
            }

            else
            {
                if(how)
                {
                    t1[i] = '(';
                    t2[i] = ')';
                    curr1++; curr2--;
                }
                else
                {
                    t1[i] = ')';
                    t2[i] = '(';
                    curr1--; curr2++;
                }

                how = !how;
            }

            if(curr1 < 0 || curr2 < 0) ans = false;
        }

        if(curr1 != 0 || curr2 != 0) ans = false;

        if(!ans)
        {
            cout << "NO\n";
        }

        else
        {
            cout << "YES\n" << t1 << "\n" << t2 << "\n";
        }
    }
}