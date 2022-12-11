def count0(x)
	ans, mul = 0, 5
	ans, mul = ans + x / mul, mul * 5 while mul <= x
	ans
end

n = gets.strip.to_i
beg = 0
beg += 1 while count0(beg) < n
ans = []
while count0(beg) == n
	ans.push(beg)
	beg += 1
end
puts ans.length
puts ans.map(&:to_s).join(' ')