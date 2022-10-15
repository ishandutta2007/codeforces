import Data.List
import Control.Monad

n = 5

calc2 :: [[Int]] -> [Int] -> Int
calc2 a (b:c:d) = (a !! b !! c) + (a !! c !! b) + (calc2 a d)
calc2 _ _ = 0

calc :: [[Int]] -> [Int] -> Int
calc a (c:b) = (calc2 a (c:b)) + (calc a b)
calc _ _ = 0

solve :: [[Int]] -> Int
solve a = maximum $ map (calc a) $ permutations [0..n-1]

main = do
          s <- replicateM 5 $ (getLine >>= (return . (map read) . words))
          print $ solve s