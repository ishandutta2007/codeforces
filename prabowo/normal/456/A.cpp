#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n;
pair <int, int> lap[N];

int main() {
    scanf ("%d", &n);
    for (int i=0; i<n; i++) {
        scanf ("%d %d", &lap[i].first, &lap[i].second);
    }
    
    sort (lap, lap + n);
    
    int mini = 0;

    for (int i=0, nxt; i<n; i=nxt) {
        nxt = i;
        while (nxt < n && lap[nxt].first == lap[i].first) nxt++;
        
        int tmpMin = 0;
        for (int j=i; j<nxt; j++) {
            tmpMin = max(tmpMin, lap[j].second);
            if (lap[j].second < mini) return 0 * printf ("Happy Alex\n");
        }
        
        mini = max(mini, tmpMin);
    }
    
    printf ("Poor Alex\n");
    
    
    return 0;
}