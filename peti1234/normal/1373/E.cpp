#include <bits/stdc++.h>

using namespace std;
int w, n, k;
string s, x;
char c='0';
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while(w--) {
        cin >> n >> k, s.clear();
        for (int i=0; i<=9; i++) for (int j=0; j<=20; j++) {
            int sum=0; x.clear();
            for (int p=i; p<=i+k; p++) {
                sum+=p%10;
                if (p<10) sum+=9*j;
                else sum++;
            }
            sum=n-sum;
            if (sum%(k+1)==0 && sum>=0) {
                sum/=(k+1);
                int q=min(sum, 8); sum-=q;
                if (sum%9) x+=c+sum%9;
                while(sum>=9) sum-=9, x+='9';
                if (q) x+=c+q;
                for (int i=1; i<=j; i++) x+='9';
                x+=c+i;
                if (s.size()==0 || (s.size()>x.size() || (s.size()==x.size() && s>x))) s=x;
            }
        }
        if (s.size()==0) cout << -1 << "\n";
        else cout << s << "\n";
    }
    return 0;
}