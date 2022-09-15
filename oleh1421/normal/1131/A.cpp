#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int used[100002];
int used1[100002];
int main()
{
    //int n;cin>>n;
    int w1,h1,w2,h2;cin>>w1>>h1>>w2>>h2;
    if (w1>w2){
        swap(w1,w2);
        swap(h1,h2);
    }
    int res=w1+2*(h1+1)+w2+2*(h2+1);
    res+=w2-w1;
    cout<<res;
    return 0;
}