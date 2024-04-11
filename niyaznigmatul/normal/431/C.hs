import Data.List
import Control.Monad

mod' :: Int
mod' = 1000000007

add :: Int -> Int -> Int
add a b = mod (a + b) mod'


solve :: [Int] -> Int
solve [n, k, d] = solve' n !! 1 !! 0
        where 
              solve' 0 = [[1], [0]]
              solve' n = [a:dp1, (add (b-a) mod'):dp2]
                  where [dp1, dp2] = solve' (n - 1)
                        a = foldl add 0 $ take (d - 1) dp1
                        b = foldl add 0 $ concat $ map (take k) [dp1, dp2]
                        


main = getLine >>= (putStrLn . show . solve . (map read) . words)