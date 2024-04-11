import Control.Monad
import Control.Applicative
import Data.List

readInt :: IO Integer
readInt = read <$> getLine

readIntList :: IO [Integer]
readIntList = fmap read . words <$> getLine

main :: IO ()
main = do
  [n, k] <- readIntList
  li <- sort <$> readIntList
  putStrLn $ show $ li !! (fromIntegral (n-k))