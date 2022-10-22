#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int main(void) {
    int n;
    scanf("%d\n", &n);
    queue<int> q;
    int used[100001];
    for(int i=0;i<=100000;i++) {
    	used[i]=0;
    }
    for(int i=0;i<n;i++) {
        int x;
        scanf("%d ", &x);
        q.push(x);
    }
    scanf("\n");
    int sum=0;
    for(int i=0;i<n;i++) {
    	if (q.empty()) {
    		break;
    	}
        while (used[q.front()]==1) {
            q.pop();
        }
        int x;
        scanf("%d ", &x);
        if (q.front()!=x) {
            sum+=1;
            used[x]=1;
        }
        if (q.front()==x) {
        	q.pop();
        }
    }
    printf("%d", sum);
    return 0;
}