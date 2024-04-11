import std.stdio;
import std.algorithm;
 
void main() {
	int n;
	scanf("%d", &n);
	int a, cnt1, cnt0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		if (a & 1) ++cnt1;
		else ++cnt0;
	}
	int ans = min(cnt0, cnt1);
	cnt1 -= ans;
	ans += cnt1 / 3;
	printf("%d", ans);
}