import Data.List

solve :: [Integer] -> Integer
solve [n, m, a] = (div (n + a - 1)  a) * (div (m + a - 1) a)

--splitTokens :: String -> [String]
--splitTokens "" = []
--splitTokens (x:xs) = getTokens (x:xs) ""
--                    where getTokens "" s = [s]
--                          getTokens (y:ys) s = if y == ' ' the
main = do
    z <- getLine
    putStrLn $ show $ solve $ map read (words z)