import Data.List

solve :: Integer -> [Integer] -> Integer
solve x [] = 0
solve x (a:b) = (a * x) + (solve (max (x - 1) 1) b)

main = do
        first <- getLine >>= (return . (map read) . words)
        second <- getLine >>= (return . sort . (map read) . words)
        putStrLn $ show $ solve (first !! 1) second