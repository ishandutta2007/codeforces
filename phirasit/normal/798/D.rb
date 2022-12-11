n = gets.strip.to_i
a = gets.strip.split.map(&:to_i)
b = gets.strip.split.map(&:to_i)

c = (0...n).sort { |i, j| a[j] <=> a[i] }

ans = [c[0]]
for i in (1...n).step(2)
    if i == n-1 or b[c[i]] > b[c[i+1]]
        ans.push(c[i])
    else
        ans.push(c[i+1])
    end
end
puts ans.length
puts ans.map { |i| i+1 }.map(&:to_s).join(' ')