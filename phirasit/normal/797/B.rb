n = gets.strip.to_i
data = gets.split.map(&:to_i)

even = data.select { |x| x > 0 and x % 2 == 0 }
odd_pos = data.select { |x| x > 0 and x % 2 == 1 }
odd_neg = data.select { |x| x < 0 and x % 2 == 1 }

if odd_pos.length > 0
    odd_neg.push(-odd_pos.min)
    exchange = (odd_pos.length % 2 == 0 ? [-odd_pos.min, odd_neg.max].max : 0)
    puts (even.reduce(0, :+) + odd_pos.reduce(:+) + exchange)
else
    puts (even.reduce(0, :+) + odd_neg.max)
end