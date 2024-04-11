

solve n d a = if s + (n - 1) * 10 <= d then ((n - 1) * 2 + (div (d - s - 10 * (n - 1)) 5)) else (-1)
        where s = sum a

main = do
        first <- getLine >>= (return . (map read) . words)
        second <- getLine >>= (return . (map read) . words)
        n <- return $ first !! 0
        d <- return $ first !! 1
        putStrLn $ show $ solve n d second