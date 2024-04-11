#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
stack < pair < int , int > > s;
char str[N];
int num;
vector < string > depth[N];
int mx;
int main(){
    s.push({0 , N});
    do{
        scanf("%[^,]" , str);
        getchar();
        scanf("%d" , &num);
        auto it = s.top();
        s.pop();
        depth[it.first + 1].push_back(str);
        mx = max(mx , it.first + 1);
        if(it.second > 1){
            s.push({it.first , it.second - 1});
        }
        if(num){
            s.push({it.first + 1 , num});
        }
    }while(getchar() != '\n');
    printf("%d\n" , mx);
    for(int i = 1 ; i <= mx ; ++i){
        for(auto it : depth[i]){
            for(char c : it){
                putchar(c);
            }
            putchar(' ');
        }
        printf("\n");
    }
}