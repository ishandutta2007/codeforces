#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int matrix[111][111], n, tmp1, tmp2, c1=0, c2=0;
pair<int, int> cur1, cur2;

void query(int val, bool chk1){
    if (chk1){
        matrix[cur1.first][cur1.second]=val;
        printf("%d %d %d\n", val, cur1.first+1, cur1.second+1);
        fflush(stdout);
        cur1.second += 2;
        if (cur1.second>=n){
            if (n&1) cur1.second-=n;
            else{
                if (cur1.second&1) cur1.second=0;
                else cur1.second=1;
            }
            cur1.first++;
        }
        c1++;
    }
    else{
        matrix[cur2.first][cur2.second]=val;
        printf("%d %d %d\n", val, cur2.first+1, cur2.second+1);
        fflush(stdout);
        cur2.second += 2;
        if (cur2.second>=n){
            if (n&1) cur2.second-=n;
            else{
                if (cur2.second&1) cur2.second=0;
                else cur2.second=1;
            }
            cur2.first++;
        }
        c2++;
    }
}

int main(){
    scanf("%d", &n);
    tmp1=(n*n)/2, tmp2=(n*n)/2;
    if (n&1) tmp1++;
    cur2.second=1;
    while(c1<tmp1 && c2<tmp2){
        int a;
        scanf("%d", &a);
        if (a==1) query(2, 0);
        else query(1, 1);
    }
    if (c1==tmp1){
        while(c2<tmp2){
            int a;
            scanf("%d", &a);
            if (a==2) query(3, 0);
            else query(2, 0);
        }
    }
    else{
        while(c1<tmp1){
            int a;
            scanf("%d", &a);
            if (a==1) query(3, 1);
            else query(1, 1);
        }
    }
    return 0;
}