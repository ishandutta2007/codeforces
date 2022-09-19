#include <bits/stdc++.h>

using namespace std;
int w, n, k, pos;
string s;
bool jo(int a) {
    return s[a]-k+1=='a';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k >> s;
        for (int i=0; i<n;) {
            pos=i;
            if (s[i]=='a' || s[i]=='b' || jo(i)) {
                s[i]='a';
                i++;
                continue;
            }
            if (i+1<n && jo(i+1)) {
                s[i+1]='a';
                swap(s[i], s[i+1]);
                i+=2;
            }
            else {
                if (i+1<n && s[i+1]<s[pos]) pos=i+1;
                if (i+2<n && s[i+2]+1<s[pos]) pos=i+2;
                if (s[pos]=='a' || pos==i+2) s[i]--;
                else s[pos]--;
                if (pos==i+1) swap(s[i], s[i+1]);
                if (pos==i+2) swap(s[i+2], s[i+1]), swap(s[i], s[i+1]);
                i=pos+1;
            }
            while(i<n) {
                if (i+1<n && s[i+1]<min(s[i-1], s[i])) swap(s[i+1], s[i]), swap(s[i-1], s[i]), i+=2;
                else if (s[i]<s[i-1]) swap(s[i], s[i-1]), i++;
                else break;
            }
        }
        cout << s << "\n";
    }
    return 0;
}