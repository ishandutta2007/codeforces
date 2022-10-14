#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N,T,ans[200005],A[200005],X[200005],way[200005];
bool cek(ll arr[]){
    // arr[0]=0;
    // if (arr[1]>=1)
    for (ll i=2; i<=N; i++){
        if (arr[i-1]<arr[i]) continue;
        else return false;
    }
    for (ll i=N; i>=1; i--){
        if (X[i]==X[i-1]){
            if (A[i]<=ans[i-1]) continue;
            return false;
        }
    }
    // if (is_sorted(arr+1, arr+N+1)) return true;
    return true;
}
bool cek2(ll arr[], ll ck[]){
    // arr[0]=0;
    
    for (ll i=1; i<=N; i++){
        if (arr[i]==ck[i]) continue;
        return false;
    }
    return true;
    
}

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> T;
    for (ll i=1; i<=N; i++) cin >> A[i];
    for (ll i=1; i<=N; i++){cin >> X[i]; way[X[i]]=X[i];}
    for (ll i=N; i>=1; i--){
        if (way[i]==0) way[i]=way[i+1];
    }

    if (!cek2(X,way)){
        cout << "No\n";
        return 0;
    }
    A[N+1]=3000000000000000000 -T+1;
    for (ll i=N; i>=1; i--){
        ll ori=X[i];
        ll ai=i;
        while (X[i-1]==ori){
            i--;
        }
        // ans[i-1]=A[i]-1;
        // ans[i]=A[ai];
        ans[ai]=A[ai+1]-1;
        for (ll k=ai-1; k>=i; k--){
            ans[k]=ans[k+1]-1;
        }
        if (A[i]>ans[i]){
            cout << "No\n";
            return 0;
        }
    }

    if (!cek(ans)){
        cout << "No\n";
    } else{
        cout << "Yes\n";
        for (ll i=1; i<=N; i++){
            cout << ans[i]+T;
            if (i<N) cout << " ";
        }
        cout << "\n";
    }
}

/*
5 0
10 20 30 40 50
3 3 4 4 5

37 38 40 49 |50

 */