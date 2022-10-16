#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    char c;
    int n,m;
    int cnt = 0;
    int mx = 0;
    scanf("%d %d",&m,&n);
    for(int i = 0;i<n;i++){
        int cr = 0;
        for(int j = 0;j<m;j++){
            cin >> c;
            if(c == '1') cr ++;
        }
        if(cr == m){
            mx = max(mx,cnt);
            cnt = 0;
        }
        else{
            cnt++;
        }

    }
    mx = max(mx,cnt);
    printf("%d\n",mx);
}