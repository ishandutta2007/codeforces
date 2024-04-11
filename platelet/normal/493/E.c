typedef long long ll;
ll a, b, c;
find(ll x, ll y) {
	if(!x || !y) return 0; ll v = y % b;
	return ((x - v) % a ? 0 : find((x - v) / a, (y - v) / b)) + (x == y);
}
main() {
	scanf("%lld%lld%lld", &a, &b, &c);
	if(a == 1 && b == 1) puts(c > 1 ? "0" : "inf");
	else printf("%d", find(b, c));
}