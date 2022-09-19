#include <bits/stdc++.h>

using namespace std;
int w, n;
long long inv[5][5], db[5], sum, maxi;
string s, ans;
vector<int> p;

int valt(char a) {
    if (a=='A') {
        return 1;
    }
    if (a=='N') {
        return 2;
    }
    if (a=='T') {
        return 3;
    }
    if (a=='O') {
        return 4;
    }
}
char vvalt(int c) {
    if (c==1) {
        return 'A';
    }
    if (c==2) {
        return 'N';
    }
    if (c==3) {
        return 'T';
    }
    if (c==4) {
        return 'O';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> s;
        n=s.size(), maxi=-1;
        for (int i=0; i<n; i++) {
            int x=valt(s[i]);
            for (int j=1; j<=4; j++) {
                inv[x][j]+=db[j];
            }
            db[x]++;
        }
        p.clear();
        for (int i=1; i<=4; i++) {
            p.push_back(i);
        }
        for (int s=0; s<24; s++) {
            sum=0;
            for (int a=0; a<4; a++) {
                for (int b=a+1; b<4; b++) {
                    sum+=inv[p[a]][p[b]];
                }
            }
            if (sum>maxi) {
                maxi=sum;
                ans.clear();
                for (int i:p) {
                    for (int j=0; j<db[i]; j++) {
                        ans+=vvalt(i);
                    }
                }
            }
            next_permutation(p.begin(), p.end());
        }
        cout << ans << "\n";
        for (int i=1; i<=4; i++) {
            db[i]=0;
            for (int j=1; j<=4; j++) {
                inv[i][j]=0;
            }
        }
    }
    return 0;
}
/*
1
AN
*/