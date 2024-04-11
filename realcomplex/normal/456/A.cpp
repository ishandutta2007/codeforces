#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define se second

int main() {

    int n;
    cin >> n;
    int a,b;
    vector<pair <int,int> >lap;
    for(int i = 0;i<n;i++){
        cin >> a >> b;
        lap.push_back(make_pair(b,a));
    }
    bool t = false;
    sort(lap.begin(),lap.end());
    for(int i = 1;i<n;i++){
        if(lap[i].se < lap[i - 1].se){
            t = true;
            break;
        }
    }
    if(t == false){
        cout << "Poor Alex\n";
    }
    else{
        cout << "Happy Alex\n";
    }
	return 0;
}