#include<bits/stdc++.h>
using namespace std;
char s[1000000];
vector<pair<char,int> > v;
int main() {
    int n;
    scanf("%s",s);
    int c=1;
    n=strlen(s);
    char t=s[0];
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            c++;
        }
        else {
            v.push_back({t,c});
            c=1;
            t=s[i];
        }
    }
    v.push_back({t,c});
    int l=v.size();
    if(l%2==0) {
        printf("0");
        return 0;
    }
    else {
        for(int i=0;i<l/2;i++) {
            if(v[i].first!=v[l-i-1].first || v[i].second+v[l-i-1].second<3) {
                printf("0");
                return 0;
            }
        }
        if(v[l/2].second<2) printf("0");
        else printf("%d",v[l/2].second+1);
    }
}