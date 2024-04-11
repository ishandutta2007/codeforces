n = gets.strip.to_i
data = gets.strip.split.map(&:to_i).push(0)

if data.reduce(:gcd) > 1
    puts "YES", 0
else
    ans = 0
    for i in (0...n)
        next if data[i] % 2 == 0
        ans += 2 - data[i+1] % 2
        data[i+1] = 0
    end
    puts "YES", ans
end