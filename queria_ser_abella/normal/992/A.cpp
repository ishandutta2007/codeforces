#include <bits/stdc++.h>
#define maxn 300300
#define pb push_back
#define pii pair<int,int>
using namespace std;

int main() {
    set<int> s;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        if(a) s.insert(a);
    }
    printf("%d\n",s.size());
}