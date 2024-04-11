#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

vector<long long> tree;
vector<long long> lazy;

void build(vector<long long> &a, int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = a[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(a, 2*node, start, mid);
        // Recurse on the right child
        build(a, 2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, long long val)
{
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

long long queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node] != 0)
    {
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    long long p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    long long p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}


int main()
{
    int n, q;
    cin >> n >> q;

    tree = vector<long long>(4 * n);
    lazy = vector<long long>(4 * n);

    vector<long long> a(n);
    vector<long long> b(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    build(b, 1, 0, n - 1);

    for(int i = 0; i < q; ++i)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        updateRange(1, 0, n - 1, l - 1, r - 1, 1);
    }

    vector<long long> freq(n);
    for(int i = 0; i < n; ++i)
    {
        freq[i] = queryRange(1, 0, n - 1, i, i);
    }

    sort(a.begin(), a.end());
    sort(freq.begin(), freq.end());

    long long sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += freq[i] * a[i];
    }

    cout << sum;

    return 0;
}