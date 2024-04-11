#include <bits/stdc++.h>
using namespace std;

vector<int> p[2];
vector<int> d1, d2;

void manacher(const string& u){
    int n = u.size();
    p[0].resize(n + 1);
    p[1].resize(n);
    for(int z = 0; z<2; z++){
        for(int i = 0, l = 0, r = 0; i<n; i++){
            int t = r - i +!z;
            if(i<r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while(L >= 1 && R+1 <n && u[L - 1] == u[R + 1])
                p[z][i]++, L--, R++;
            if(R>r) l = L, r = R;
        }

    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int ans = 0;
        string s;
        cin >> s;
        int d, h;
        d = 0;
        h = s.size() - 1;

        while(d <= h && s[d] == s[h]){
            d++, h--;
        }

        string answ;
        string u = "";
        for(int i = 0; i<=s.size(); i++){
            if(i < d ) answ.push_back(s[i]);
            else if(i <= h) u.push_back(s[i]);
        }

        ans += s.size() - u.size();
        int ma = 0;
        d1.resize(u.size());
        d2.resize(u.size());
        int n = u.size();
        //cout << n << endl;

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && u[i - k] == u[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && u[i - k - 1] == u[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }

        for(int i = 0; i<u.size(); i++){
            if(i - d1[i] == -1) ma = max(ma, 2*i + 1);
            if(i<u.size()) if(i - d2[i] == 0) ma = max(ma, 2*i);
        }

        reverse(u.begin(), u.end());

        int maa = ma;
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && u[i - k] == u[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        /*for(int i: d2){
            cout << i << " ";
        }
        cout << endl;*/

        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && u[i - k - 1] == u[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }

        for(int i = 0; i<u.size(); i++){
            if(i - d1[i] == -1) ma = max(ma, 2*i + 1);
            if(i<u.size()) if(i - d2[i] == 0) ma = max(ma, 2*i);
        }

        ans += ma;

        if(ma == maa){
            for(int i = 0; i<ma; i++){
                answ.push_back(u[u.size() - 1 - i]);
            }
        }

        else{
            for(int i = 0; i<ma; i++){
                answ.push_back(u[i]);
            }
        }

        for(int i = 0; i<s.size(); i++){
            if(i > h && i >= d) answ.push_back(s[i]);
            //else u.push_back(s[i]);
        }
        cout << answ << endl;
    }

}