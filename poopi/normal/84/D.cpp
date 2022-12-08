                                /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

#define int64 long long
#define P pair<int, int>

int64 k;
int n;
P arr[100010];

bool cmp(P a, P b){
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    while(cin >> n >> k){
        int64 sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i].first);
            arr[i].second = i;
            sum += arr[i].first;
        }
        if(sum < k){
            cout << -1 << endl;
            continue;
        }
        if(sum == k){
            cout << endl;
            continue;
        }
        sort(arr, arr + n);
        int bef = 0;
        for(int i = 0; true; i++){
            int64 dif = arr[i].first - bef;
            if(dif == 0)
                continue;
            int64 x = min(dif, k / (n - i));
            k -= x * (n - i);
            bef += x;
            if(x < dif)
                break;
            //cout << arr[i].first << ' '<< arr[i].second << ' ' << k << endl;
        }
        //cout << bef << endl;
        sort(arr, arr + n, cmp);
        int p = 0;
        while(k){
            if(arr[p].first > bef){
                k--;
                arr[p].first--;
            }
            p++;
        }
        /*for(int i = 0; i < n; i++){
            cout << arr[i].first << ' ' << arr[i].second << endl;
        }*/
        bool fir = true;
        for(int i = 0; i < n; i++){
            if(arr[(i + p) % n].first > bef){
                if(!fir)
                    cout << ' ';
                fir = false;
                cout << (i + p) % n + 1;
            }
        }
        cout << endl;
    }
    return 0;
}