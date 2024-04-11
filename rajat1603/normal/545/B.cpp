#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 100001;
string a , b;
int main(){
    cin>>a;
    cin>>b;
    int n = a.size();
    int dist = 0;
    for(int i = 0;i<n;++i){
        if(a[i]!=b[i]){
            dist++;
        }
    }
    if(dist&1){
        printf("impossible\n");
        return 0;
    }
    int target = dist>>1;
    int cur = 0;
    string temp;
    for(int i = 0 ; i<n;++i){
        if(a[i]==b[i]){
            temp+=a[i];
            continue;
        }
        if(a[i]!=b[i]&&cur<target){
            cur++;
            temp+=b[i];
            continue;
        }
        if(a[i]!=b[i]&&cur>=target){
            temp+=a[i];
            continue;
        }
    }
    cout<<temp;
}