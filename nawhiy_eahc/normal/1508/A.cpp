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
        string a, b, c; cin >> a >> b >> c;
        int cnta = 0, cntb = 0, cntc = 0;
        for(int i=0;i<2*n;i++)
        {
            if(a[i] == '0') cnta++;
            if(b[i] == '0') cntb++;
            if(c[i] == '0') cntc++;
        }

        if(cnta > cntb)
        {
            swap(a, b); swap(cnta, cntb);
        }
        if(cntb > cntc)
        {
            swap(b, c); swap(cntb, cntc);
        }
        if(cnta > cntb)
        {
            swap(a, b); swap(cnta, cntb);
        }

        if(cntb <= n)
        {
            int i = 0, j = 0, cnt = 0;
            for(int T = 0; T < 2*n-cnta;T++)
            {
                while(i < 2*n && a[i] == '0')
                {
                    cout << "0";
                    i++; cnt++;
                }
                while(j < 2*n && b[j] == '0')
                {
                    cout << "0";
                    j++; cnt++;
                }
                cout << "1";
                i++; j++; cnt++;
            }
            while(i < 2*n && a[i] == '0')
            {
                cout << "0"; i++; cnt++;
            }
            while(j < 2*n && b[j] == '0')
            {
                cout << "0";
                j++; cnt++;
            }
            for(int T=0;T<3*n-cnt;T++) cout << "0";
            cout << "\n";
        }
        else
        {
            int i = 0, j = 0, cnt = 0;
            for(int T = 0; T < cntc;T++)
            {
                while(i < 2*n && b[i] == '1')
                {
                    cout << "1";
                    i++; cnt++;
                }
                while(j < 2*n && c[j] == '1')
                {
                    cout << "1";
                    j++; cnt++;
                }

                cout << "0";
                i++; j++; cnt++;
            }

            while(i < 2*n && b[i] == '1')
                {
                    cout << "1";
                    i++; cnt++;
                }
                while(j < 2*n && c[j] == '1')
                {
                    cout << "1";
                    j++; cnt++;
                }

            for(int T=0;T<3*n-cnt;T++) cout << "0";
            cout << "\n";
        }
    }
}