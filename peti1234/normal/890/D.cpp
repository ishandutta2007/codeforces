#include <bits/stdc++.h>

using namespace std;
vector <char> s{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int t[31][31];
int k[31];
int v[31];
bool g[31];
bool gg[31];
int aa[31];
int main()
{
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        if (s.size()>26) {
            cout << "NO" << endl;
            return 0;
        }
        for (int j=0; j<s.size(); j++) {
            for (int k=j+1; k<s.size(); k++) {
                if (s[j]==s[k]) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        int ll=s[0]-'a'+1;
        gg[ll]=true;
        for (int j=1; j<s.size(); j++) {
            int x=s[j-1]-'a'+1;
            gg[x]=true;
            int y=s[j]-'a'+1;
            gg[y]=true;
            if (t[x][y]==0) {
                t[x][0]++;
                aa[y]++;
                if (aa[y]>1) {
                    cout << "NO" << endl;
                    return 0;
                }
                if (t[x][0]>1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            t[x][y]=1;
            k[y]=x;
            v[x]=y;
        }
    }
    for (int i=1; i<=26; i++) {
        if (!g[i]) {
            int x=i;
            int y=i;
            while (x!=0) {
                g[x]=true;
                x=v[x];
                if (y==x) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    for (int i=1; i<=26; i++) {
        if (k[i]==0 && gg[i]) {
            int x=i;
            while(x!=0) {
                cout << s[x-1];
                x=v[x];
            }
        }
    }
    return 0;
}