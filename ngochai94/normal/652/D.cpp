#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

int getSum(int BITree[], int index)
{
    int sum = 0; // Iniialize result

    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];

        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}

// Updates a node in Binary Index Tree (BITree) at given index
// in BITree.  The given value 'val' is added to BITree[i] and
// all of its ancestors in tree.
void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;

    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
       // Add 'val' to current node of BI Tree
       BITree[index] += val;

       // Update index to that of parent in update View
       index += index & (-index);
    }
}

// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);

    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";

    return BITree;
}

int n,l[200005],r[200005],ans[200005],rnk[200005];
pair<int,int> p[200005];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    For(i,0,n)
    {
        cin>>l[i]>>r[i];
        p[i]={r[i],i};
        //p[i*2+1]={r[i],i+mid};
        //s.insert(r[i]);
        ans[i]=-1;
    }
    sort(p,p+n);
    For(i,0,n) rnk[p[i].second]=i;
    For(i,0,n) p[i]={l[i],i};
    sort(p,p+n);
    int *BITree = constructBITree(ans, n);
    //updateBIT(BITree,n,1,0);
    //cout<<getSum(BITree,3);return 0;
    For(i,0,n)
    {
        int ind=p[i].second;
        int x=rnk[ind];
        ans[ind]=-1-getSum(BITree,x);
        updateBIT(BITree,n,x,1);
        //ans[ind]=s.order_of_key(x);
        //s.erase(x);
    }
    For(i,0,n) cout<<ans[i]<<endl;
}