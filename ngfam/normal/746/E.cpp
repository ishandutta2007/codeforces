/*** Riven is not just my life :) ***/

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 1e6 + 1, mod = 1e9 + 7;

int n, a[N], m, odd[N], even[N], nodd, neven, ok[N], cntodd[N], cnteven[N];
int done[N], fk[N];

vector < int > ansodd, anseven;

typedef pair<int,int> ii;
ii ginz[N];

void MAIN(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d", a + i);
        if(a[i] % 2 == 0) even[++neven] = a[i];
        else odd[++nodd] = a[i];

        if(a[i] <= n) ok[a[i]] = 1;
        ginz[i] = ii(a[i], i);
    }

    sort(odd + 1, odd + nodd + 1);
    sort(even + 1, even + neven + 1);
    int base = n / 2;

    int calcodd = 0, calceven = 0;
    for(int i = 1; i <= nodd; ++i){
        calcodd += (odd[i] != odd[i - 1]);
        if(odd[i] != odd[i - 1]){
            if(ansodd.size() < base) ansodd.push_back(odd[i]);
        }
    }
    for(int i = 1; i <= neven; ++i){
        calceven += (even[i] != even[i - 1]);
        if(even[i] != even[i - 1]){
            if(anseven.size() < base) anseven.push_back(even[i]);
        }
    }


    int needodd = max(0, (base - calcodd));
    int needeven = max(0, (base - calceven));

    int bigodd = 0, bigeven = 0;

    for(int i = 1; i <= n; ++i){
        cntodd[i] = cntodd[i - 1];
        cnteven[i] = cnteven[i - 1];

        if(i % 2 == 0) cnteven[i] += (i % 2 == 0 && !ok[i]);
        else cntodd[i] += (i % 2 == 1 && !ok[i]);

        if(cntodd[i] == needodd && needodd != 0){
            if(bigodd == 0){
                bigodd = i;
            }
        }
        if(cnteven[i] == needeven && needeven != 0){
            if(bigeven == 0){
                bigeven = i;
            }
        }
    }

    if(m < max(bigodd, bigeven)){
        puts("-1");
        return;
    }

    int outodd = nodd - calcodd;
    int outeven = neven - calceven;

    printf("%d\n", needodd + needeven);
    for(int i = 1; i <= n; ++i){
        if(!ok[i]){
            if(i % 2 == 1){
                if(needodd > 0){
                    ansodd.push_back(i);
                    --needodd;
                }
            }
            else{
                if(needeven > 0){
                    anseven.push_back(i);
                    --needeven;
                }
            }
        }
    }

    vector < int > ans;

    for(int i = 0; i < base; ++i){
        ans.push_back(ansodd[i]);
        ans.push_back(anseven[i]);
    }
    sort(ans.begin(), ans.end());
    sort(ginz + 1, ginz + n + 1);

    int d = 1;
    for(int i = 0; i < ans.size(); ++i){
        while(ans[i] > ginz[d].first && d <= n) ++ d;
        if(d <= n && ans[i] == ginz[d].first){
            done[i] = 1;
            fk[ginz[d].second] = 1;
        }
    }

    int low = 0;
    for(int i = 1; i <= n; ++i){
        if(!fk[i]){
            while(done[low]) ++low;
            printf("%d ", ans[low]);
            ++low;
        }
        else{
            printf("%d ", a[i]);
        }
    }
}