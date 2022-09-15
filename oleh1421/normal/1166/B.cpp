#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int used[1001];
int main()
{
    int k;cin>>k;
    string s="aeiou";
    for (int t=1;t*t<=k;t++){
        if (k%t) continue;
        int n=t;
        int m=k/t;
        if (n<5) continue;
        if (m<5) continue;
        string cur="";
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                 cur+=s[(i+j)%5];
            }
        }
        cout<<cur<<endl;
        return 0;
    }
    cout<<-1;
    return 0;
}