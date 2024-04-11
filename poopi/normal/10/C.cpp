                    /* in the name of Allah */
#include<iostream>
#include<cmath>
using namespace std;

#define Max 1000001

long long n, s1, s2;
long long cnt[10];
bool mark[Max];
int pr[100000], pnt;

int d(int x){
    int t = x % 9;
    return (t == 0 ? 9 : t);
}

void find_prime(){
    for(int i = 2; i < Max; i++){
        if(!mark[i]){
            pr[pnt++] = i;
            for(int j = i + i; j < Max; j += i)
                mark[j] = true;
        }
    }
}

int main(){
    find_prime();
    cin >> n;
    for(int i = 1; i <= n; i++){
        int ni = i, sum = 1;
        for(int j = 0; j < pnt && pr[j] * pr[j] <= ni; j++){
            int cnt = 1;
            while((ni % pr[j]) == 0){
                ni /= pr[j];
                cnt++;
            }
            sum *= cnt;
        }
        if(ni > 1)
            sum *= 2;
        s2 += sum;
    }
    for(int i = 1; i < 10; i++){
        cnt[i] = n / 9;
        if(n % 9 >= i)
            cnt[i]++;
    }
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            for(int k = 0; k < 9; k++)
                if(d(i * j) == d(k))
                    s1 += cnt[d(i)] * cnt[d(j)] * cnt[d(k)];
    cout << s1 - s2 << endl;
    return 0;
}