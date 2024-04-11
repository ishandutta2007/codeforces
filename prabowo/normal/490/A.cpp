#include<bits/stdc++.h>
using namespace std;


int main(){
    int w;
    cin >> w;
    vector <int> t1,t2,t3;
    for (int i=0; i<w; i++){
        int t;
        cin >> t;
        if (t == 1) t1.push_back(i+1);
        if (t == 2) t2.push_back(i+1);
        if (t == 3) t3.push_back(i+1);
    }
    int maks = min(t1.size(), min(t2.size(), t3.size()));
    printf("%d\n", maks);
    for (int i=0; i<maks; i++){
        cout << t1[i] << " " << t2[i] << " " << t3[i] << endl;
    }
    return 0;
}