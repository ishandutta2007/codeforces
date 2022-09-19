import Control.Applicative

main = do
  [a, b] <- fmap read . words <$> getLine :: IO [Integer]
  let x = b*(b-1)`div`2*(a+a*(a+1)`div`2*b)
  putStrLn.show $ x `mod` 1000000007