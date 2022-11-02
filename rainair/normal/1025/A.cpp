#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int N;
int p[27];

int main(){
    scanf("%d",&N);
    std::string str;
    std::cin >> str;
    for(int i = 0;i < N;i++){
        p[str[i]-'a'+1]++;
    }
    bool flag = false;
    for(int i = 1;i <= 26;i++){
        if(p[i] > 1) flag = true;
        // DEBUG(i);DEBUG(p[i]);
    }
    if(N == 1){
        printf("Yes");
        return 0;
    }
    if(flag) {
        printf("Yes");
    }
    else printf("No");
    return 0;
}