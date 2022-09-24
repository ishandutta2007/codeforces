#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
using namespace std;


typedef long long LL;

string s;
int d[100010];

int main() {
    cin>>s;
    stack<int>st;
    int n=s.size();

    for (int i=0; i<n; i++) {
        if (s[i]=='(' || s[i]=='[') st.push(i);
        else {
            if (st.size()==0) {
                d[i]=-1;
            } else {
                int p=st.top(); st.pop();
                char c=s[p];
                if (c=='(' && s[i]==']' || c=='[' && s[i]==')') {
                    d[i]=-1;
                    d[p]=-1;
                    for (;st.size();) {
                        int x=st.top(); st.pop();
                        d[x]=-1;
                    }
                }
            }
        }
    }
    for (;st.size();) {
        int x=st.top(); st.pop();
        d[x]=-1;
    }

    d[n]=-1;
    int l, r, cnt, t;
    l=r=0;
    cnt=t=0;
    for (int i=0, p=0; i<=n; i++) {
        if (d[i]<0) {
            if (cnt>t) {
                l=p; r=i;
                t=cnt;
            }
            p=i+1;
            cnt=0;
        } else {
            if (s[i]=='[') cnt++;
        }
    }

    printf("%d\n%s\n", t, s.substr(l, r-l).c_str());
    return 0;
}