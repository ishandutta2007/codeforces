// LuffyKai
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>
#include <time.h>
#include <limits.h>
#include <ctype.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

bool debugging = false;
#define printDebug if(debugging)printf

int record[100000] = {0};
int main(){
    int s, k;
    scanf("%d%d", &s, &k);
    if (s==1) {
        printf("2\n0 1\n");
        return 0;
    }
    if (s==2) {
        printf("2\n0 2\n");
        return 0;
    }
    for (int i=0;i<100000;i++) record[i]= 0;
    record[0] =0;
    record[1]= 1;
printDebug("zzz%d\n", k);
    int i;
    for (i=2;record[i-1]<s;i++) {
        if (i >=k+1) {
            record[i] = 2*record[i-1] - record[i-k-1];
        }
        else {
            record[i]=0;
            for (int j=i-1;j>=0;j--) {
                record[i]+=record[j];
            }
        }
        printDebug("%d : %d\n", i, record[i]);
    }
    int xd[i+1];
    for (int j=0;j<=i;j++) xd[j]=0;
    
    int j=i;
    int count=0;
    vector<int> ans;
    while(s>0) {
        if (record[j]==0) {j--;continue;}
        // if (record[j] == s && count ==0) {
        //  j--;
        //  continue;
        //  printDebug("%d zz\n", j);
        // }
        if (record[j] <= s) {
            printDebug("troll %d %d %d\n", j, record[j], s);
            s-=record[j];
            count++;
            ans.push_back(record[j]);
            xd[j]++;
        }
        else {
            j--;
        }
    }
    for (int t=i;t>=1;) {
        if (xd[t] > 1) {
            xd[t]--;
            for (int tt = t-1;tt>=t-k && tt >= 0;tt--) xd[tt] ++;
        } 
        else{
            t--;
        }
    }
    count = 0;
    ans.clear();
    for (int t = i;t>=1;t--) {
        if (xd[t]) {
            assert(xd[t]==1);
            count++;
            ans.push_back(record[t]);
        }
    }
    if (count == 1) {
        printf("2\n");
        printf("%d 0\n", ans[0]);
        return 0;
    }
    printf("%d\n", count);
    for (vector<int>::iterator it = ans.begin();it!=ans.end();) {
        printf("%d", *it);
        it++;
        if (it==ans.end()) {
            printf("\n");
            break;
        }else {
            printf(" ");
        }
    }
    return 0;
}