#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int cur=n;
        if (cur==3){
            printf("2\n3 2\n3 2\n");
            continue;
        }
        if (cur==4){
            printf("3\n3 4\n4 2\n4 2\n");
            continue;
        }
        int m=0;
        vector<int> pos;
        while(cur>5){
            if (cur>500){
                m += cur-500+1;
                pos.push_back(cur);
                cur=500;
            }
            if (cur>25){
                m += cur-25+1;
                pos.push_back(cur);
                cur=25;
            }
            if (cur>5){
                m += cur-5+1;
                pos.push_back(cur);
                cur=5;
            }
        }
        printf("%d\n", m+5);
        for (int x:pos){
            int i, j;
            if (x>500) i=501;
            else if (x>25) i=26;
            else if (x>5) i=6;
            j=i-1;
            for (i=i;i<x;i++){
                printf("%d %d\n", i, x);
            }
            printf("%d %d\n", x, j);
            printf("%d %d\n", x, j);
        }
        printf("4 5\n5 3\n5 3\n3 2\n3 2\n");
    }
    return 0;
}