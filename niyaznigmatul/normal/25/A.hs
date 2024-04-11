import Data.List

solve :: [Int] -> Int
solve a = let
            b = [x | x <- a, mod x 2 == 0];
            c = [x | x <- a, odd x];
            in
                let mb = elemIndex (head (f b c)) a in
                    case mb of
                        Nothing -> error "oo"
                        Just a -> a + 1


f :: [Int] -> [Int] -> [Int]
f a b = if (length a == 1) then a else b

main = do {
    z1 <- getLine;
    z2 <- getLine;
    putStrLn $ show $ solve $ map read (words z2)
}